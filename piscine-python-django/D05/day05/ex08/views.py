from django.shortcuts import render
from django.http import HttpResponse
import psycopg2 as pg2
from django.conf import settings
import io


def init_file():
    path = f'{settings.BASE_DIR}/ex08'
    new_content = ''
    with open(f'{path}/planets.csv', 'r') as file:
        lines = file.readlines()
        for i, l in enumerate(lines):
            new = f'{i}	' + l
            new_content += new
    with open(f'{path}/planets.csv', 'w') as file:
        file.write(new_content)

    new_content = ''
    with open(f'{path}/people.csv', 'r') as file:
        lines = file.readlines()
        for i, l in enumerate(lines):
            new = f'{i}	' + l
            new_content += new
    with open(f'{path}/people.csv', 'w') as file:
        file.write(new_content)


def init(request):
    try:
        connect = pg2.connect('host=localhost dbname=djangotraining user=djangouser password=djangouser')
        with connect.cursor() as cur:
            cur.execute('''
            CREATE TABLE ex08_planets
            (
                id SERIAL PRIMARY KEY,
                name VARCHAR(64) UNIQUE NOT NULL,
                climate VARCHAR,
                diameter INT,
                oribital_period INT,
                population BIGINT,
                rotation_period INT,
                surface_water REAL,
                terrain VARCHAR(128)
            );

            CREATE TABLE ex08_people
            (
                id SERIAL PRIMARY KEY,
                name VARCHAR(64) UNIQUE NOT NULL,
                birth_year VARCHAR(32),
                gender VARCHAR(32),
                eye_color VARCHAR(32),
                hair_color VARCHAR(32),
                height INT,
                mass REAL,
                homeworld VARCHAR(64) REFERENCES ex08_planets(name)
            );
            ''')
#            init_file()
            connect.commit()
            return HttpResponse('OK')

    except Exception as e:
        return HttpResponse(str(e))


def populate(request):
    try:
        connect = pg2.connect('host=localhost dbname=djangotraining user=djangouser password=djangouser')

        path = f'{settings.BASE_DIR}/ex08'

        with connect.cursor() as cur:
            with open(f'{path}/planets.csv', 'r') as file:
                cur.copy_from(file, 'ex08_planets', null="NULL")
                connect.commit()
            with open(f'{path}/people.csv', 'r') as file:
                cur.copy_from(file, 'ex08_people', null="NULL")
                connect.commit()
            return HttpResponse('OK')
            
    except Exception as e:
        return HttpResponse(str(e))

def display(request):
    try:
        connect = pg2.connect('host=localhost dbname=djangotraining user=djangouser password=djangouser')
        with connect.cursor() as cur:
            cur.execute("SELECT * from ex08_planets;")
            planets = cur.fetchall()
            cur.execute("SELECT * from ex08_people ORDER BY name asc;")
            people = cur.fetchall()
    except Exception as e:
        print(e)
        return HttpResponse("No data available")
    if people and planets:
        return render(request, 'ex08/display.html', {'people': people, 'planets': planets})
    else:
        return HttpResponse("No data available")
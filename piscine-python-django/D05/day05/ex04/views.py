from django.shortcuts import render
import psycopg2 as pg2
from django.http import HttpResponse
from django.forms import Form

def create_table(cur, content):
    vals = '(\n'
    i = 0
    for key, value in content.items():
        i += 1
        if i < len(content):
            vals += f'   {key} {value}, \n'
        else:
            vals += f'   {key} {value}\n'
    vals += ')'
    try:
        cur.execute(f'CREATE TABLE ex04_movies {vals};')
        return 'OK'
    except Exception as e:
        return str(e)
        

def init(request):
    ret = ''
    try:
        with pg2.connect('host=localhost dbname=djangotraining user=djangouser password=djangouser') as connect:
            try:
                cur = connect.cursor()
                ret = create_table(cur, {
                        'title': 'varchar(64) UNIQUE NOT NULL',
                        'episode_nb': 'INTEGER PRIMARY KEY',
                        'opening_crawl': 'TEXT',
                        'director': 'varchar(32) NOT NULL',
                        'producer': 'varchar(128) NOT NULL',
                        'release_date': 'DATE NOT NULL'
                })
                connect.commit()
            except Exception as e:
                ret = str(e)
    except Exception as e:
        ret = str(e)
    connect.close()
    return HttpResponse(ret)


def insert_table(cur, content):
    category = ''
    vals = ''
    i = 0
    try:
        for key, value in content.items():
            i += 1
            if i < len(content):
                category += f'{key}, '
                vals += f"'{value}', "
            else:
                category += f'{key}'
                vals += f"'{value}'"
        cur.execute(f'''\
        INSERT INTO ex04_movies ({category}) VALUES\n({vals})
        ON CONFLICT DO NOTHING
        ;''')
    except Exception as e:
        return (str(e))
    return 'OK'

        

def populate(request):
    ret = ''
    try:
        connect = pg2.connect('host=localhost dbname=djangotraining user=djangouser password=djangouser')
    except Exception as e:
        return HttpResponse(str(e))
    cur = connect.cursor()
    contents = [
        {
            'title': 'The Phantom Menace',
            'episode_nb': 1,
            'opening_crawl': '',
            'director': 'George Lucas',
            'producer': 'Rick McCallum',
            'release_date': '1999-05-19',
        },
        {
            'title': 'Attack of the Clones',
            'episode_nb': 2,
            'opening_crawl': '',
            'director': 'George Lucas',
            'producer': 'Rick McCallum',
            'release_date': '2002-05-16',
        },
        {
            'title': 'Revenge of the Sith',
            'episode_nb': 3,
            'opening_crawl': '',
            'director': 'George Lucas',
            'producer': 'Rick McCallum',
            'release_date': '2005-05-19',
        },
        {
            'title': 'A New Hope',
            'episode_nb': 4,
            'opening_crawl': '',
            'director': 'George Lucas',
            'producer': 'Gary Kurtz, Rick McCallum',
            'release_date': '1977-05-25',
        },
        {
            'title': 'The Empire Strikes Back',
            'episode_nb': 5,
            'opening_crawl': '',
            'director': 'Irvin Kershner',
            'producer': 'Gary Kurtz, Rick McCallum',
            'release_date': '1980-05-17',
        },
        {
            'title': 'Return of the Jedi',
            'episode_nb': 6,
            'opening_crawl': '',
            'director': 'Richard Marquand',
            'producer': 'Howard G. Kazanjian, George Lucas, Rick McCallum',
            'release_date': '1983-05-25',
        },
        {
            'title': 'The Force Awakens',
            'episode_nb': 7,
            'opening_crawl': '',
            'director': 'J. J. Abrams',
            'producer': 'Kathleen Kennedy, J. J. Abrams, Bryan Burk',
            'release_date': '2015-12-11',
        }
    ]
    for movie in contents:
        ret = insert_table(cur, movie)
    try:
        connect.commit()
    except Exception as e:
        return HttpResponse(str(e))
    return HttpResponse(ret)


def display(request):
    with pg2.connect('host=localhost dbname=djangotraining user=djangouser password=djangouser') as connect:
        try:
            curr = connect.cursor()
            curr.execute("SELECT * from ex04_movies")
            data = curr.fetchall()
        except Exception:
            return HttpResponse("No data available")
    if data:
        return render(request, 'ex04/display.html', {'data': data})
    else:
        return HttpResponse("No data available")

def remove_table(nb, key):
    with pg2.connect('host=localhost dbname=djangotraining user=djangouser password=djangouser') as connect:
        curr = connect.cursor()
        tablename = 'ex04_movies'
        curr.execute(f'DELETE FROM {tablename} WHERE {tablename}.{nb}={key}')
        connect.commit()

def remove(request):
    if request.method == 'POST':
        form = Form(request.POST)
        key = request.POST.get('Movies')
        if form.is_valid() and key:
            remove_table('episode_nb', key)
        else:
            return HttpResponse("No data available")

    with pg2.connect('host=localhost dbname=djangotraining user=djangouser password=djangouser') as connect:
        try:
            curr = connect.cursor()
            curr.execute("SELECT * from ex04_movies")
            data = curr.fetchall()
            if data:
                return render(request, 'ex04/remove.html', {'data': data})
            else:
                return HttpResponse("No data available")
        except Exception:
            return HttpResponse("No data available")
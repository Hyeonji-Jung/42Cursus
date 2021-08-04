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
        cur.execute(f'CREATE TABLE ex06_movies {vals};')
        return 'OK'
    except Exception as e:
        return str(e)
        

def init(request):
    ret = ''
    try:
        with pg2.connect('host=localhost dbname=djangotraining user=djangouser password=djangouser') as connect:
            cur = connect.cursor()
            ret = create_table(cur, {
                'title': 'varchar(64) UNIQUE NOT NULL',
                'episode_nb': 'INTEGER PRIMARY KEY',
                'opening_crawl': 'TEXT',
                'director': 'varchar(32) NOT NULL',
                'producer': 'varchar(128) NOT NULL',
                'release_date': 'DATE NOT NULL',
                'created': 'TIMESTAMP NOT NULL DEFAULT LOCALTIMESTAMP',
                'updated': 'TIMESTAMP NOT NULL DEFAULT LOCALTIMESTAMP'
            })
            connect.commit()
            if ret != 'OK':
                return HttpResponse(ret)
            try:
                cur.execute('''\
CREATE OR REPLACE FUNCTION update_changetimestamp_column()
RETURNS TRIGGER AS $$
BEGIN
NEW.updated = now();
NEW.created = OLD.created;
RETURN NEW;
END;
$$ language 'plpgsql';
CREATE TRIGGER update_films_changetimestamp BEFORE UPDATE
ON ex06_movies FOR EACH ROW EXECUTE PROCEDURE
update_changetimestamp_column();''')
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
        INSERT INTO ex06_movies ({category}) VALUES\n({vals})
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
            curr.execute("SELECT * from ex06_movies")
            data = curr.fetchall()
        except Exception:
            return HttpResponse("No data available")
    if data:
        return render(request, 'ex06/display.html', {'data': data})
    else:
        return HttpResponse("No data available")


def update(request):
    connect = pg2.connect('host=localhost dbname=djangotraining user=djangouser password=djangouser')
    cur = connect.cursor()

    if request.method == 'POST':
        form = Form(request.POST)
        key = request.POST.get('Movies')
        text = request.POST.get('Text')
        if form.is_valid() and key:
            try:
                cur.execute(f"""UPDATE ex06_movies SET opening_crawl = '{text}' WHERE episode_nb = {key};""")
                connect.commit()
            except Exception as e:
                print(e)
                return HttpResponse("No data available")
        else:
            return HttpResponse("No data available")

    try:
        curr = connect.cursor()
        curr.execute("SELECT * from ex06_movies")
        data = curr.fetchall()
        if data:
            return render(request, 'ex06/update.html', {'data': data})
        else:
            return HttpResponse("No data available")
    except Exception:
        return HttpResponse("No data available")
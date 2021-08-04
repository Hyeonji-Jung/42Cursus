from django.shortcuts import render
import psycopg2 as pg2
from django.http import HttpResponse

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
        cur.execute(f'CREATE TABLE ex02_movies {vals};')
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
    for key, value in content.items():
        i += 1
        if i < len(content):
            category += f'{key}, '
            vals += f"'{value}', "
        else:
            category += f'{key}'
            vals += f"'{value}'"
    try:
        cur.execute(f'INSERT INTO ex02_movies ({category}) VALUES\n({vals});')
        return 'OK'
    except Exception as e:
        return str(e)


def populate(request):
    ret = ''
    try:
        with pg2.connect('host=localhost dbname=djangotraining user=djangouser password=djangouser') as connect:
            try:
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
                    if ret != 'OK':
                        break
                connect.commit()

            except Exception as e:
                ret = str(e)
    except Exception as e:
        ret = str(e)
    return HttpResponse(ret)


def display(request):
    with pg2.connect('host=localhost dbname=djangotraining user=djangouser password=djangouser') as connect:
        try:
            curr = connect.cursor()
            curr.execute("SELECT * from ex02_movies")
            data = curr.fetchall()
        except Exception:
            return HttpResponse("No data available")
    if data:
        return render(request, 'ex02/display.html', {'data': data})
    else:
        return HttpResponse("No data available")

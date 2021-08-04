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
        cur.execute(f'CREATE TABLE ex00_movies {vals};')
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
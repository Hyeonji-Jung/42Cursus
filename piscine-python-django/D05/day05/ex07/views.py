from datetime import time
from django.shortcuts import render
from django.http import HttpResponse
from ex07.models import Movies
from django.forms import Form
from django.utils import timezone


def populate(request):
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
    try:
        for movie in contents:
            insert = Movies(**movie)
            if not insert.created:
                insert.created = timezone.now()
            insert.updated = timezone.now()
            insert.save()
    except Exception as e:
        print(e)
        return HttpResponse("No data available")
    return HttpResponse('OK')


def display(request):
    try:
        data = Movies.objects.all()
    except:
        return HttpResponse("No data available")
    if data:
        return render(request, 'ex07/display.html', {'data': data})
    else:
        return HttpResponse("No data available")


def update(request):
    if request.method == 'POST':
        form = Form(request.POST)
        key = request.POST.get('Movies')
        text = request.POST.get('Text')
        if form.is_valid() and key and text:
            Movies.objects.filter(episode_nb=key).update(opening_crawl=text)
            Movies.objects.filter(episode_nb=key).update(updated=timezone.now())
        else:
            return HttpResponse("No data available")
    data = Movies.objects.all()
    if data:
        return render(request, 'ex07/update.html', {'data': data})
    else:
        return HttpResponse("No data available")
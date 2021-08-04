from django.shortcuts import render
from django.http import HttpResponse
from ex05.models import Movies
from django.forms import Form


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
            insert.save()
    except Exception as e:
        return HttpResponse(str(e))
    return HttpResponse('OK')

def display(request):
    try:
        data = Movies.objects.all()
    except:
        return HttpResponse("No data available")
    if data:
        return render(request, 'ex05/display.html', {'data': data})
    else:
        return HttpResponse("No data available")

def remove(request):
    if request.method == 'POST':
        form = Form(request.POST)
        key = request.POST.get('Movies')
        if form.is_valid() and key:
            Movies.objects.filter(episode_nb=key).delete()
        else:
            return HttpResponse("No data available")
    data = Movies.objects.all()
    if data:
        return render(request, 'ex05/remove.html', {'data': data})
    else:
        return HttpResponse("No data available")
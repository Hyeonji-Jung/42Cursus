from django.http.response import HttpResponse
from django.shortcuts import render
from ex09.models import People

def display(request):
    try:
        people = People.objects.values('name', 'homeworld__name', 'homeworld__climate').order_by('name')
        if not people:
            return HttpResponse("No data available, please use the following command line before use: python3 manage.py loaddata ex09/ex09_initial_data.json")
        return render(request, 'ex09/display.html', {'people': people})
    except:
        return HttpResponse("No data available, please use the following command line before use: python3 manage.py loaddata ex09/ex09_initial_data.json")
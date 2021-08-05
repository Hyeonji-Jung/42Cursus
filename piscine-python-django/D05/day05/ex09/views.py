from django.shortcuts import render

def display(request):
    return render(request, 'ex08/display.html', {'people': people, 'planets': planets})
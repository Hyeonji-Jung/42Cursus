from django.shortcuts import render


def table(request):
    return render(request, 'ex03/table.html', {'colors' : range(0, 255, 5)})
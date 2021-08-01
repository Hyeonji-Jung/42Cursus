from django.shortcuts import render
from django.http import HttpResponseRedirect
from django.conf import settings
from .forms import MyForm
import logging

def submit(request):
    logger = logging.getLogger('logs')
    if request.method == 'POST':
        form = MyForm(request.POST)
        if form.is_valid():
            logger.info(form.cleaned_data['content'])
        return HttpResponseRedirect('/ex02')
    try:
        with open(settings.LOG_FILE, 'r') as f:
            data_logs = f.readlines()
    except:
        data_logs = []
    return render(request, 'ex02/form.html', {'form' : MyForm(), 'log' : data_logs})
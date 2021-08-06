from django.shortcuts import render, redirect
from django.conf import settings
from django.contrib import auth
from django.contrib.auth.decorators import login_required
from ex.forms import *
from ex.models import *
import random

def main(request):
    tips = Tip.objects.all().order_by('date')

    response = render(request, 'ex/main.html', {'tips': tips})
    if not request.COOKIES.get('username'):
        random_user = random.choice(settings.USER_NAME_POOL)
        request.COOKIES['username'] = random_user
        response = render(request, 'ex/main.html', {'tips': tips})
        response.set_cookie('username', random_user, max_age=42)

    if request.user.is_authenticated:
        form = TipForm
        if request.method == 'POST':
            if request.POST.get('up') or request.POST.get('down'):
                tip = Tip.objects.get(pk=request.POST.get('up') or request.POST.get('down'))
                if request.POST.get('up'):
                    tip.upvote(request.user)
                    return redirect('/')
                else:
                    tip.downvote(request.user)
                    return redirect('/')
            if request.POST.get('delete'):
                Tip.objects.get(pk=request.POST.get('delete')).delete()
                return redirect('/')

            tmp_form = TipForm(request.POST)
            if tmp_form.is_valid():
                tip = Tip(content=request.POST['content'], author=request.user)
                tip.save()
                tips = Tip.objects.all().order_by('date')
        response = render(request, 'ex/main.html', {'tips': tips, 'form': form})
    return response

def login(request):
    if request.user.is_authenticated:
        return redirect('/')
    form = LoginForm()
    if request.method == 'POST':
        form = LoginForm(request.POST)
        if form.is_valid():
            data = form.cleaned_data
            user = auth.authenticate(username=data['username'], password=data['password'])
            if user:
                auth.login(request, user)
                return redirect('/')
    return render(request, 'ex/login.html', {'form': form})

def register(request):
    if request.user.is_authenticated:
        return redirect('/')
    form = RegisterForm()
    if request.method == 'POST':
        form = RegisterForm(request.POST)
        if form.is_valid():
            user = get_user_model().objects.create_user(
                username = request.POST['username'],
                password = request.POST['password']
            )
            auth.login(request, user)
            return redirect('/')
    return render(request, 'ex/register.html', {'form': form})


def logout(request):
    if request.user.is_authenticated:
        auth.logout(request)
    return redirect('/')

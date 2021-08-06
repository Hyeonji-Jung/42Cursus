from django import forms
from django.contrib.auth import authenticate, get_user_model
from django.conf import settings
from django.forms import widgets
from ex.models import *

class RegisterForm(forms.Form):
    username = forms.CharField(max_length=32, required=True, widget=forms.TextInput(attrs={'class': 'form_control', 'placeholder': 'username'}), label='username')
    password = forms.CharField(max_length=64, required=True, widget=forms.PasswordInput(attrs={'class': 'form_control', 'placeholder': 'password'}), label='password')
    confirm_password = forms.CharField(max_length=64, required=True, widget=forms.PasswordInput(attrs={'class': 'form_control', 'placeholder': 'confirm password'}), label='confirm password')

    def clean(self):
        cleaned = super().clean()
        username = cleaned.get('username')
        password = cleaned.get('password')
        confirm_password = cleaned.get('confirm_password')
        try:
            MyUser.objects.get(username=username)
            self.add_error('username', 'This username is already exist')
        except:
            pass
        if password != confirm_password:
            self.add_error('confirm_password', 'Passwords do not match')


class LoginForm(forms.Form):
    username = forms.CharField(max_length=32, required=True, widget=forms.TextInput(attrs={'class': 'form_control', 'placeholder': 'username'}), label='username')
    password = forms.CharField(max_length=64, required=True, widget=forms.PasswordInput(attrs={'class': 'form_control', 'placeholder': 'password'}), label='password')

    def clean(self):
        cleaned = super().clean()

        if not authenticate(
            username = cleaned.get('username'),
            password = cleaned.get('password')):
            self.add_error('username', 'User does not exist')
            self.add_error('password', 'User does not exist')


class TipForm(forms.ModelForm):
    class Meta:
        model = Tip
        fields = ['content']
        widgets = {
            'content': widgets.Textarea(attrs={'class': 'form-control', 'placeholder': 'Enter some tips'})
        }

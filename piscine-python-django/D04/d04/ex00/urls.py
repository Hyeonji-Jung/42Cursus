from django.urls import path
from ex00 import views

urlpatterns = [
    path('', views.ex00, name='ex00')
]
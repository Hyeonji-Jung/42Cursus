from django import forms

class   MyForm(forms.Form):
    content = forms.CharField(label="Name", max_length=10)
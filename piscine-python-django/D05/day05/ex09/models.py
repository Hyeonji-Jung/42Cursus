from django.db import models
from django.db.models.fields import BigIntegerField, BooleanField, CharField, DateTimeField, IntegerField

class Planets(models.Model):
    name = CharField(unique=True, max_length=64, null=False)
    climate = CharField()
    diameter = IntegerField()
    orbital_period = IntegerField()
    population = BigIntegerField()
    rotation_period: IntegerField()
    surface_water: BooleanField()
    terrain = CharField()
    created = DateTimeField()
    updated = DateTimeField()

    def __str__(self):
        return self.name


class People(models.Model):
    name = CharField(max_length=64, null=False)
    birth_year = CharField(max_length=32)
    gender = CharField(max_length=32)
    eye_color = CharField(max_length=32)
    hair_color = CharField(max_length=32)
    height = IntegerField()
    mass = BooleanField()
    homeworld = models.OneToOneField(related_name='name')
    created = DateTimeField()
    updated = DateTimeField()

    def __str__(self):
        return self.name
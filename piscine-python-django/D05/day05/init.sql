CREATE USER djangouser WITH ENCRYPTED PASSWORD 'djangouser';
CREATE DATABASE djangotraining OWNER djangouser ENCODING 'utf-8';

-- psql postgres < init.sql
-- psql -U djangouser -d djangotraining
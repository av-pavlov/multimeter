# -*- coding: utf-8 -*-
import os
import sys
from datetime import datetime
from flask_seasurf import SeaSurf
from flask import Flask
from multimeter import users, settings, tasks
from multimeter.user_views import user_bp
from multimeter.admin_views import admin_bp


# Настройка Flask
app = Flask(__name__)
app.config['SECRET_KEY'] = 'b3ae4cfc3de6b0f6be6f82c751e0175554f47a5b61ee5f2be7fc1fd0b312bf71'
app.config['DEBUG'] = app.config['TESTING'] = settings.development
app.config['PORT'] = settings.port
if not os.path.isdir(settings.work_dir):
    print("Work folder", settings.work_dir, "not found !!!")
    sys.exit()

# Настройка плагинов
sea_surf = SeaSurf(app)


@app.context_processor
def multimeter_context():
    return {
        'settings': settings,
        'tasks': tasks,
        'users': users,
    }


@app.context_processor
def time_left():
    t = settings.end_time - datetime.now()
    sec = int(t.total_seconds())
    return {
        'now': datetime.now(),
        'time_left': max(sec, 0),
    }


app.register_blueprint(user_bp, url_prefix=settings.url_prefix)
app.register_blueprint(admin_bp, url_prefix=settings.url_prefix)

if __name__ == '__main__':
    if settings.waitress:
        from waitress import serve

        serve(app, port=settings.port)
    else:
        app.run(host='0.0.0.0', port=settings.port)

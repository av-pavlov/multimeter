# -*- coding: utf-8 -*=
import os
import sys
from argparse import ArgumentParser
from datetime import datetime

from collections import OrderedDict
from multimeter.helpers import load_json, get_value, save_json


class Settings:
    def __init__(self, work=None):
        # Значения по умолчанию
        self.start_time = datetime(1, 1, 1)  # время начала олимпиады
        self.freeze_time = datetime(1, 1, 1)  # время заморозки таблицы результатов
        self.end_time = datetime(1, 1, 1)  # время завершения олимпиады
        self.password = ''  # пароль администратора
        self.registration_enabled = False  # регистрация пользователей
        self.results_format = 'individual'  # индивидуальный / командный режим выдачи результатов
        self.show_results = False  # показывать результаты участникам
        self.statement_file = ''  # файл с результатами
        self.summary = 'hide'  # ???
        self.testing = 'started'  # ???
        self.title = ''  # заголовок системы
        self.users_attributes = OrderedDict()  # дополнительные атрибуты пользователей

        # Запуск из тестов
        self.port = 80  # номер TCP-порта для входящих соединений
        self.work = '' if work is None else work  # рабочий каталог
        self.waitress = False  # запуск в сервера режиме Waitress
        self.development = False  # отладочный режим
        self.url_prefix = ''  # префикс URL

        if sys.argv[0][-9:].lower() == 'server.py' or sys.argv[0][-10:].lower() == 'arbiter.py':
            # Разбор параметров командной строки
            parser = ArgumentParser(description='Веб-сервер для проверки олимпиадных задач по программированию')
            parser.add_argument('-p', '--port', default=80, type=int, help="номер TCP-порта для входящих соединений")
            parser.add_argument('-w', '--work', default='work', type=str, help="рабочий каталог")
            parser.add_argument('-ws', '--waitress', action="store_true", help="запуск сервера в режиме Waitress")
            parser.add_argument('-d', '--development', action="store_true", help="отладочный режим")
            parser.add_argument('-up', '--url_prefix', default='', help="префикс URL")
            parser.parse_args(namespace=self)
            if self.url_prefix and not self.url_prefix.startswith('/'):
                self.url_prefix = '/' + self.url_prefix

        self.work_dir = os.path.join(os.getcwd(), self.work)  # Рабочий каталог
        self.load()

    def __setitem__(self, key, value):
        self.__dict__[key] = value

    def __getitem__(self, item):
        return self.__dict__.get(item, None)

    def __contains__(self, item):
        return item in self.__dict__

    def load(self):
        settings = load_json('settings.json', {}, self.work_dir)
        self.end_time = get_value(settings, 'end_time', datetime, datetime(1, 1, 1))
        self.freeze_time = get_value(settings, 'freeze_time', datetime, datetime(1, 1, 1))
        self.password = get_value(settings, 'password', str, '')
        self.registration_enabled = get_value(settings, 'registration_enabled', bool, False)
        self.results_format = get_value(settings, 'results_format', str, 'individual')
        self.show_results = get_value(settings, 'show_results', bool, False)
        self.start_time = get_value(settings, 'start_time', datetime, datetime(1, 1, 1))
        self.statement_file = get_value(settings, 'statement_file', str, '')
        self.summary = get_value(settings, 'summary', str, 'hide')  # ???
        self.testing = get_value(settings, 'testing', str, 'started')  # ???
        self.title = get_value(settings, 'title', str, '')
        self.users_attributes = get_value(settings, 'users_attributes', OrderedDict, OrderedDict())

    def save(self):
        settings = dict(
            # end_time=self.end_time,
            # freeze_time=self.freeze_time,
            # start_time=self.start_time,
            password=self.password,
            registration_enabled=self.registration_enabled,
            results_format=self.results_format,
            show_results=self.show_results,
            statement_file=self.statement_file,
            start_time=self.start_time.isoformat(),
            freeze_time=self.freeze_time.isoformat(),
            end_time=self.end_time.isoformat(),
            summary=self.summary,
            testing=self.testing,
            title=self.title,
            users_attributes=self.users_attributes,
        )
        save_json(settings, 'settings.json', self.work_dir)

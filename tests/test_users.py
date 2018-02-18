# -*- coding: utf-8 -*-
import json
import os

from flask import session
from multimeter import users, Users, settings
from server import app
from tests import TestView
from unittest import TestCase


class TestUsers(TestCase):
    def test_type(self):
        self.assertIsInstance(users, Users)


class TestUsersViews(TestView):
    def test_login(self):
        """ Проверка авторизации пользователя """

        # Создаем тестового пользователя
        users.clear()
        users['user1'] = dict(password='12345')

        with app.test_client() as client:
            # Вылогиниваемся
            response = client.get('/logout/')
            self.assertEqual(302, response.status_code)
            self.assertNotIn('username', session)

            # Должна открыться страница авторизации
            response = client.get('/login/')
            self.assertEqual(200, response.status_code)
            self.should_have(['Авторизация', 'Логин', 'Пароль', 'Войти'], response)

            # Неправильно ввели логин и пароль - должно быть сообщение об ошибке
            response = client.post('/login/', data=dict(
                username='wrong',
                password='wrong',
            ))
            self.assertEqual(200, response.status_code)
            self.should_have(['Неправильный логин или пароль', 'Авторизация', 'Логин', 'Пароль', 'Войти'], response)
            self.assertNotIn('username', session)

            # Правильно ввели логин и пароль - должно быть перенаправление на главную страницу
            response = client.post('/login/', data=dict(
                username='user1',
                password='12345',
            ))
            self.assertEqual(302, response.status_code)
            self.assertIn('username', session)

            # Пользователь уже вошел в систему - должно быть перенаправление на главную страницу
            response = client.get('/login/')
            self.assertEqual(302, response.status_code)

    def test_logout(self):
        """ Проверка выхода пользователя из системы """

        # Создаем тестового пользователя
        users.clear()
        users['user1'] = dict(password='12345')

        with app.test_client() as client:
            # Авторизируемся
            client.post('/login/', data=dict(username='user1', password='12345'))

            # Выход из системы, должно быть перенаправлениен на /login/
            response = client.get('/logout/')
            self.assertEqual(302, response.status_code)
            self.assertNotIn('username', session)

    def test_register(self):
        """ Проверка регистрации нового пользователя """

        # Создаем тестового пользователя
        users.clear()
        users['user1'] = dict(password='12345')

        with app.test_client() as client:
            # Выходим из системы
            client.get('/logout/')

            # Страница регистрации не должна открыться если это запрещено в конфигурации
            settings.registration_enabled = False
            response = client.get('/register/')
            self.assertEqual(404, response.status_code)

            # Должна открыться страница регистрации
            settings.registration_enabled = True
            response = client.get('/register/')
            self.assertEqual(200, response.status_code)
            self.should_have(['Регистрация', 'Логин', 'Пароль', 'Подтверждение пароля', 'Зарегистрироваться'], response)

            # Должна быть ошибка - пользователь уже существует
            response = client.post('/register/', data=dict(
                username='user1',
                password='12345',
                confirm='12345',
            ))
            self.assertEqual(200, response.status_code)
            self.should_have(['Логин уже существует'], response)
            self.assertNotIn('username', session)

            # Должна быть ошибка - пароли разные
            response = client.post('/register/', data=dict(
                username='user2',
                password='password1',
                confirm='password2',
            ))
            self.assertEqual(200, response.status_code)
            self.should_have(['Пароли не совпадают'], response)
            self.assertNotIn('username', session)

            # Успешный вход - должно быть перенаправление на главную страницу
            response = client.post('/register/', data=dict(
                username='user2',
                password='68790',
                confirm='68790',
            ))
            self.assertEqual(302, response.status_code)
            self.assertIn('username', session)

            # Пользователь уже вошел в систему - должно быть перенапрвление на главную страницу
            response = client.post('/login/', data=dict(
                username='user2',
                password='67890',
            ))
            self.assertEqual(302, response.status_code)

            # Данные о новом пользователе должны сохраниться в файле
            users_file = open(users.filename, encoding='UTF-8')
            users_data = json.load(users_file)
            self.assertIn('user2', users_data)
            users_file.close()

            # Удалим вновь созданный файл
            os.remove(users.filename)

    # def test_admin_users(self):
    #
    #     users.clear()
    #     users['user1'] = dict(password='12345')
    #
    #     with app.test_client() as client:
    #         response = client.get('/admin/users/')
    #         self.assertEqual(200, response.status_code)
    #         self.should_have(['Пользователи', 'Логин', 'Добавить пользователя'], response)

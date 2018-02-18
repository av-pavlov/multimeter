# -*- coding: utf-8 -*=
from multimeter import tasks
from unittest import TestCase


class TestEmptySettings(TestCase):
    def setUp(self):
        super(TestEmptySettings, self).setUp()

    def test_empty_tasks(self):

        # Задачи должны быть пустым словарем
        self.assertEqual(0, len(tasks))

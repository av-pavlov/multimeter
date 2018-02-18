# -*- coding: utf-8 -*=
from unittest import TestCase
from multimeter import settings, Settings


class TestSettings(TestCase):

    def test_type(self):
        self.assertIsInstance(settings, Settings)

# -*- coding: utf-8 -*=
from unittest import TestCase
from multimeter import languages, Languages


class TestSettings(TestCase):

    def test_type(self):
        self.assertIsInstance(languages, Languages)

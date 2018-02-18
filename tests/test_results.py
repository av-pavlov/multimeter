# -*- coding: utf-8 -*=
from unittest import TestCase
from multimeter import results, Results


class TestSettings(TestCase):

    def test_type(self):
        self.assertIsInstance(results, Results)

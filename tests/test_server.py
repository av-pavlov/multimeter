# -*- coding: utf-8 -*=
from flask import Flask
from server import app
from tests import TestView


class TestApp(TestView):
    def test_type(self):
        self.assertIsInstance(app, Flask)

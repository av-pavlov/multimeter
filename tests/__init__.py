# -*- coding: utf-8 -*=
from unittest import TestCase


def s(string):
    return bytes(source=string, encoding='utf-8')


class TestView(TestCase):

    def should_have(self, members, response):
        if isinstance(members, list):
            for fragment in members:
                self.assertIn(s(fragment), response.data)
        else:
            self.assertIn(s(members), response.data)

    def should_not_have(self, members, response):
        for fragment in members:
            self.assertNotIn(s(fragment), response.data)

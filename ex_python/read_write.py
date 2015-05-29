#!/usr/bin/env python
# -*- coding: utf-8 -*-
fp = open('test.file', "w")
fp.write("我们")
fp.close()

fp = open('test.file')
print fp.read()
fp.close()


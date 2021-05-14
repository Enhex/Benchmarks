import os
import sys
import shutil

sys.path.append(os.path.join(os.path.dirname(__file__), '..'))
from build_base import build

source = os.path.dirname(os.path.realpath(__file__))
build_path = build(source)
shutil.copy('./test.txt', build_path)

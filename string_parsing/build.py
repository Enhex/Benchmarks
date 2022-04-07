import os
import sys

sys.path.append(os.path.join(os.path.dirname(__file__), '..'))
from build_base import build

source = os.path.dirname(os.path.realpath(__file__))
build(source)
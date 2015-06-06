import functools
import os

level = 0
def trace(f):
    @functools.wraps(f)
    def g(*args):
        global level
        print "|  " * level + "|--", f.__name__, args
        
        level += 1
        result = f(*args)
        level -= 1
        return result
        
    #functools.update_wrapper(f, g)
    return g

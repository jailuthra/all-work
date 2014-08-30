def rpn(exp):
    print 'rpn called with exp = ' + exp
    i = 1
    operators = ('+', '-', '/', '*', '^')
    if len(exp) == 1:
        print 'returning ' + exp
        return exp
    else:
        exp = exp[1:-1]  # Trim out the parantheses
        for i in range(0, len(exp)):
            print 'i is ' + str(i)
            if exp[i] in operators:
                exp = rpn(exp[:i]) + rpn(exp[i+1:]) + exp[i]
                return exp
            else:
                i += 1

if __name__ == '__main__':
    n = input('')
    for x in range(0, n):
        exp = raw_input('')
        print(rpn(exp))

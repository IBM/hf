# ======================================
# IBM Corporation (C) 2018
# Nelson Mimura Gonzalez
# nmimura@us.ibm.com
# ======================================

# ------------------------------------------------------------------------------
# Argument parser for Python.
# ------------------------------------------------------------------------------

import sys

# --------------------------------------------------------------------
# Class to represent an option to be processed by the parser.
# --------------------------------------------------------------------
class Option:
    def __init__(self, **kwargs):
        self.arg      = kwargs['arg']
        self.short    = kwargs['short']
        self.params   = kwargs['params']
        self.val      = kwargs['val']
        self.default  = kwargs['default']
        self.required = kwargs['required']
        self.action   = kwargs['action']
        self.help     = kwargs['help']
        self.examples = kwargs['examples']

# --------------------------------------------------------------------
# Argument parser class.
# --------------------------------------------------------------------
class ArgParser:

    # ------------------------------------------------------
    # Prepare parser.
    # ------------------------------------------------------
    def __init__(self):
        self.options = []

        # Automatically add help option.
        self.add(Option(
            arg='--help',
            short='-h',
            params=0,
            val=None,
            default=False,
            required=False,
            action=self.parse_help,
            help='show this help message and exit',
            examples=None))

    # ------------------------------------------------------
    # Add option to parser.
    # ------------------------------------------------------
    def add(self, option):

        # Add option to list.
        self.options.append(option)

    # ------------------------------------------------------
    # Process options using arguments.
    # ------------------------------------------------------
    def process(self, args):
        self.values = {}

        # Iterate over options and process each of them.
        for option in self.options:
            self.values[option.arg] = self.process_option(option, args)

    # ------------------------------------------------------
    # Process one option.
    # ------------------------------------------------------
    def process_option(self, option, args):

        # Find matching argument.
        for i in range(len(args)):
            if args[i] == option.arg or args[i] == option.short:
                return self.process_match(option, args, i)

        # Could not find match -- use default value if possible.
        return self.process_default(option)

    # ------------------------------------------------------
    # Process option with matching argument.
    # ------------------------------------------------------
    def process_match(self, option, args, i):

        # Determine value to be used to process the option.
        if option.params:
            val = self.process_params(option, args, i)
        else:
            val = True

        # Call action on value or return value.
        if option.action:
            return option.action(val)
        else:
            return val

    # ------------------------------------------------------
    # Process parameters for option.
    # ------------------------------------------------------
    def process_params(self, option, args, i):

        if type(option.params) is int:
            return self.process_params_int(option, args, i)
        else:
            return self.process_params_special(option, args, i)

    # ------------------------------------------------------
    # Process integer parameter specification.
    # ------------------------------------------------------
    def process_params_int(self, option, args, i):

        val = []
        if option.params >= 1:
            # Iterate over parameters and populate list.
            for j in range(option.params):
                try:
                    next = args[i+1+j]
                    if next.startswith('-'):
                        raise IndexError()
                    val.append(next)
                except IndexError:
                    print 'error: missing argument parameter: %s' % (\
                            option.arg)
                    self.print_usage()
                    exit(1)

            # If single parameter, use parameter instead of list.
            if len(val) == 1:
                val = val[0]
        else:
            print 'error: invalid params: %d (%s)' % (\
                    option.params, option.arg)
            self.print_usage()
            exit(1)

        return val

    # ------------------------------------------------------
    # Process special parameter specification.
    # ------------------------------------------------------
    def process_params_special(self, option, args, i):

        val = []

        if option.params in ['*', '+', '$']:
            for j in range(i+1, len(args)):
                if args[j].startswith('-') and not option.params == '$':
                    break
                val.append(args[j])
            if option.params == '+':
                if len(val) == 0:
                    print 'error: missing parameters for argument: %s' % (\
                            option.arg)
                    self.print_usage()
                    exit(1)
        else:
            print 'error: invalid parameter value: %s' % (option.params)
            self.print_usage()
            exit(1)

        return val

    # ------------------------------------------------------
    # Process option without matching argument.
    # ------------------------------------------------------
    def process_default(self, option):
        
        if option.default != None:
            if option.action:
                return option.action(option.default)
            else:
                return option.default
        if option.required:
            print 'error: missing required argument: %s' % (option.arg)
            self.print_usage()
            exit(1)
        else:
            print 'error: missing default value: %s' % (option.arg)
            self.print_usage()
            exit(1)

    # ------------------------------------------------------
    # Get option value from parser.
    # ------------------------------------------------------
    def get(self, arg):
        
        return self.values[arg]

    # ------------------------------------------------------
    # Print program usage based on parser options.
    # ------------------------------------------------------
    def print_usage(self):

        sys.stdout.write('usage: %s ' % (sys.argv[0]))
        for option in self.options:
            if option.required:
                sys.stdout.write('%s ' % (option.short))
                if option.val:
                    sys.stdout.write('%s ' % (option.val))
            else:
                sys.stdout.write('[%s' % (option.short))
                if option.val:
                    sys.stdout.write(' %s' % (option.val))
                sys.stdout.write('] ')
        sys.stdout.write('\n')

        flagcombos = {}
        shortlen = 0
        for option in self.options:
            if option.val:
                flagcombos[option.arg]  = '  %s %s, ' % (\
                        option.short,
                        option.val)
            else:
                flagcombos[option.arg]  = '  %s, '    % (\
                        option.short)
            shortlen = max(shortlen, len(flagcombos[option.arg]))
        flaglen = 0

        for option in self.options:
            if option.val:
                flagcombos[option.arg] += '%s%s %s'   % (\
                        (shortlen - len(flagcombos[option.arg])) * ' ',
                        option.arg,
                        option.val)
            else:
                flagcombos[option.arg] += '%s%s'      % (\
                        (shortlen - len(flagcombos[option.arg])) * ' ',
                        option.arg)
            flaglen = max(flaglen, len(flagcombos[option.arg]))
        flaglen += 3

        sys.stdout.write('\n')
        sys.stdout.write('required arguments:\n')
        for option in self.options:
            if option.required:
                sys.stdout.write('%-*s %s ' % (\
                            flaglen, 
                            flagcombos[option.arg], 
                            option.help))
                if option.default:
                    sys.stdout.write('(default: %s)' % (option.default))
                sys.stdout.write('\n')

        sys.stdout.write('\n')
        sys.stdout.write('optional arguments:\n')
        for option in self.options:
            if not option.required:
                sys.stdout.write('%-*s %s ' % (\
                            flaglen, 
                            flagcombos[option.arg], 
                            option.help))
                if option.default != None:
                    sys.stdout.write('(default: %s)' % (option.default))
                sys.stdout.write('\n')

        sys.stdout.write('\n')
        sys.stdout.write('examples:\n')
        for option in self.options:
            if option.examples:
                sys.stdout.write('  %s\n' % (option.arg))
                for example in option.examples:
                    sys.stdout.write('      %s\n' % (example))
        print

    # ------------------------------------------------------
    # Parser option action to print help.
    # ------------------------------------------------------
    def parse_help(self, bool):

        if (bool):
            self.print_usage()
            exit(0)


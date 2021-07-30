#!/usr/bin/python3


class Text(str):
    def __str__(self):
        return super().__str__().replace('<', '&lt;').replace('>', '&gt;').replace('"', '&quot;').replace('\n', '\n<br />\n')


class Elem:

    class   ValidationError(Exception):
        def __init__(self) -> None:
            super().__init__("incorrect behaviour.")

    def __init__(self, tag='div', attr={}, content=None, tag_type='double'):
        self.tag = tag
        self.attr = attr
        self.content = []
        if not (self.check_type(content) or content is None):
            raise Elem.ValidationError()
        if content:
            self.add_content(content)
        if tag_type != 'double' and tag_type != 'simple':
            raise Elem.ValidationError()
        self.tag_type = tag_type

    def __str__(self):
        attr = self.__make_attr()
        content_string = self.__make_content()
        result = "<%s%s" % (self.tag, attr)
        if self.tag_type == 'double':
            result += ">%s</%s>" % (self.__make_content(), self.tag)
        elif self.tag_type == 'simple':
            result += " />"
        return result

    def __make_attr(self):
        result = ''
        for pair in sorted(self.attr.items()):
            result += ' ' + str(pair[0]) + '="' + str(pair[1]) + '"'
        return result

    def __make_content(self):
        if len(self.content) == 0:
            return ""
        result = "\n"
        for elem in self.content:
            if len(str(elem)) != 0:
                result += "%s\n" % elem
        result = "  ".join(line for line in result.splitlines(True))
        if len(result.strip()) == 0:
            return ''
        return result

    def add_content(self, content):
        if not Elem.check_type(content):
            raise self.ValidationError()
        if type(content) == list:
            self.content += [elem for elem in content if elem != Text('')]
        elif content != Text(''):
            self.content.append(content)

    @staticmethod
    def check_type(content):
        return (isinstance(content, Elem) or type(content) == Text or
                (type(content) == list and all([type(elem) == Text or
                                                isinstance(elem, Elem)
                                                for elem in content])))
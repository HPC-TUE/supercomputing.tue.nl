from mkdocs.config.config_options import *

class HeroButton(Config):
    title = Type(str)
    url = URL()

class HeroMessageConfig(Config):
    size = Choice(["small", "medium", "large"], default="large")
    color = Choice(["default", "primary", "secondary"], default="default")
    message = Type(str)

class HeroConfig(Config):
    backdrop = Optional(Type(str))
    messages = ListOfItems(SubConfig(HeroMessageConfig), default=[])
    button = OptionallyRequired(SubConfig(HeroButton))
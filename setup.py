from setuptools import setup, Extension, find_packages

VERSION = "0.0.1"

extra_link_args = '-Wl,-rpath-link, C_code -Wl,-rpath, C_code'

extension_kwargs = {
                    "name" : "exampleAPI",
                    "sources" : ["src/pyExample.c"],
                    }

module = Extension(**extension_kwargs)

setup_kwargs = {"name" : 'exampleAPI',
                "version" : VERSION,
                "author" : 'James Haas',
                "author_email" : 'JHaasIII92@gmail.com',
                "python_requires": ">=3.7",
                "platforms" : ['Linux'],
                "ext_modules" : [module],
                "package_dir": {"": "src"},
                "package_data" : {'src': ['*.txt', 'pyExample.c', '*.src']},}

setup(**setup_kwargs)
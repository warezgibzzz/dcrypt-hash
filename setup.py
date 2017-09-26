from distutils.core import setup, Extension

dcrypt_hash_module = Extension(
    'dcrypt_hash',
    sources=['dcrypt.c', 'dcryptmodule.c'],
    include_dirs=['.'])

setup(name='dcrypt_hash',
      version='1.0',
      description='Bindings for proof of work used by Slimcoin',
      ext_modules=[dcrypt_hash_module])

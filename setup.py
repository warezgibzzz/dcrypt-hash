from distutils.core import setup, Extension

dcrypt_hash_module = Extension(
    'dcrypt_hash',
    sources=['dcrypt.cpp', 'sha256.cpp', 'uint256.cpp'],
    include_dirs=['.'],
    extra_compile_args=['-lcrypto', '-lssl'],
    libraries=['crypto', 'boost_system', 'ssl'])

setup(name='dcrypt_hash',
      version='1.0',
      description='Bindings for proof of work used by Slimcoin',
      ext_modules=[dcrypt_hash_module])

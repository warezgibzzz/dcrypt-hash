# dcrypt-hash
Dcrypt hash module for Python

Install with:

```bash
sudo python setup.py install
```

Use with:

```python
def block_header_hash(chain, header):
    import dcrypt_hash
    return dcrypt_hash.getPoWHash(header)
```

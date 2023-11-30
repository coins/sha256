# SHA256 WASM

SHA256 implementation extracted from [Bitcoin Core](https://github.com/bitcoin/bitcoin/blob/master/src/crypto/sha256.cpp) and compiled to WebAssembly.

## Usage
```js
import {ripemd160} from 'https://bitvm.github.io/sha256/sha256.js'

const preimage = new Uint8Array([97, 98, 99])    // Our preimage is "abc"
const digest = sha256(preimage)

console.log(digest)
```


## Development
The following command compiles the sources to wasm:
```sh
clang src/sha256.cpp -O2 --no-standard-libraries --target=wasm32 -Wl,--no-entry -o sha256.wasm
```

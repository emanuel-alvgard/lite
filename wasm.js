const file = await Deno.open("output.wasm", { read: true });
const wasm = await Deno.readAll(file);
Deno.close(file.rid);

const wasm_module = new WebAssembly.Module(wasm);
const wasm_instance = new WebAssembly.Instance(wasm_module);
console.log(wasm_instance.exports.main());

//build the 'lite'-compiler in js on top of Deno. 
(module
    (memory 1)

    ;;(global 

    (func $add (param i32) (param i32) (result i32)
        local.get 0
        local.get 1
        i32.add
    )
    (func $main (result i32)
        i32.const 50
        i32.const 50
        call $add
    )
    (export "main" (func $main))
)



;;functions to create:
;;array implementation
;;string implementation
;;different matrix multiplications (translation, rotation, scale, perspective etc.)


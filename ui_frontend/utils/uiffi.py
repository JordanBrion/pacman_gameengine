from cffi import FFI

class UiFfi() :
    def __init__(self):
        self.ffi = FFI()
        self.lib = self.ffi.dlopen("/home/jordanbrion/Documents/rust/pacman_gameengine/ui_backend/target/debug/libui_backend.so")
        self.ffi.cdef("""
            void create_new_project();
        """)

    def create_new_project(self):
        self.lib.create_new_project()
from cffi import FFI

class UiFfi() :
    def __init__(self):
        self.ffi = FFI()
        self.lib = self.ffi.dlopen("./ui_backend/target/debug/libui_backend.so")
        self.ffi.cdef("""
            void create_new_project(char* project_name);
        """)

    def create_new_project(self, project_name):
        self.lib.create_new_project(self.convert_to_c_str(UiFfi.encode_str(project_name)))

    def convert_to_c_str(self, your_string):
        return self.ffi.new("char[]", your_string);

    @staticmethod
    def encode_str(your_string) :
        return your_string.encode('ascii')
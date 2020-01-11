import sys
from PySide2.QtWidgets import QApplication
from ui_frontend.py.mainwindow_impl import MainWindow_Impl
from cffi import FFI
ffi = FFI()
ffi.cdef("""
    int mul(int);
""")
C = ffi.dlopen("/home/jordanbrion/Documents/rust/pacman_gameengine/ui_backend/target/debug/libui_backend.so")

print(C.mul(9))

if __name__ == "__main__":

    app = QApplication(sys.argv)

    window = MainWindow_Impl()
    window.show()

    sys.exit(app.exec_())

import sys
from PySide2.QtWidgets import QApplication
from ui_frontend.py.mainwindow_impl import MainWindow_Impl

if __name__ == "__main__":
    app = QApplication(sys.argv)

    window = MainWindow_Impl()
    window.show()

    sys.exit(app.exec_())

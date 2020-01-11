import sys
from PySide2.QtWidgets import QApplication, QMainWindow
from PySide2.QtCore import QFile
from .mainwindow_ui import Ui_MainWindow

class MainWindow_Impl(QMainWindow):
    def __init__(self):
        super(MainWindow_Impl, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
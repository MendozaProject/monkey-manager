import kivy
kivy.require('1.9.1')

from kivy.app import App
from kivy.lang import Builder
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.label import Label
from kivy.core.window import Window

Builder.load_string('''

    ''')

class MainWidget(BoxLayout):
    def __init__(self, **kwargs):
        super(MainWidget, self).__init__(**kwargs)
        BoxLayout(spacing=100)
        Window.clearcolor = (1, 1, 1, 1)
        Window.size = (1200, 700)
        lbl1 = Label(pos_hint={'x': 0, 'center_y': .97}, text = '[color=000000] To Do[/color]', markup=True)
        lbl2 = Label(pos_hint={'x': 0, 'center_y': .97}, text = '[color=000000]Doing[/color]', markup=True)
        lbl3 = Label(pos_hint={'x': 0, 'center_y': .97}, text = '[color=000000]Done[/color]', markup=True)
        self.add_widget(lbl1)
        self.add_widget(lbl2)
        self.add_widget(lbl3)

class Kanban(App):
    def build(self):
        main_layout = MainWidget()
        return main_layout

if __name__ == "__main__":
    Kanban().run()


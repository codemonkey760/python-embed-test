from component import Component

class TestComponent(Component):
    def update(self, deltaTime):
        print("Component Update called from Python with", deltaTime)

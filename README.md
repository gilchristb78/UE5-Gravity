# UE5-Gravity
In this repository I will recreate different gravity physics in UE5


### Todo:

 - [ ] Fix Rotating when Gravity Swaps
   - [ ] Currently just goes "down" a bit to avoid ground
   - [ ] should go down the by its height (collision capsule)
   - [ ] better it should slowly rotate towards the correct up vector
 - [ ] Add collision capsule to character not just blueprint
 - [X] Gravity Point
   - [X] Sphere collision
   - [X] mesh in middle
   - [X] boolean to point towads (planet)
   - [X] or away (run inside planet)
 - [ ] Character Movement
   - [ ] Accelleration
   - [ ] Cant run into stuff
 - [ ] Movement Relative to ground
  - [ ] Sin of angle between forward vector and forward of travel (parallel to ground)

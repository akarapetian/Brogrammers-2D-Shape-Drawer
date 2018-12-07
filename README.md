# Brogrammers-2D-Shape-Drawer

This is going to become our new repository.

Im trying to make the project as simple as possible, and meet all the requirements. 



BUGS:
- 7th shape isn't being read by the parser at all (FIXED)
- The third item in the vector, (the polygon) is not rendering its id alongside its shape
- NEW BUG - the shapes are being reset if you move it, move another shape, and return to moving the first one. Their positions are being reset to where the file read them in. (not worth fixing, breaks other stuff)
- Fixed a bug where the filepath was not finding the shapes.txt for the vector by putting the shapes.txt in the resources folder. However this creates a new problem where the resources folder is READ-ONLY so we cannot save to the file through that method. We have to find a way to dynamically access the shapes.txt directory. (FIXED BUT NEEDS TESTING)
- our pencolor is not appearing, only black is being used (FIXED)
- our shapes report listing is not being updated if a shape is added or deleted

Currently we need to:
- add exception handling
- add report listing for all shapes and attributes
- add shapes
- delete shapes(FINISHED)
- report shape perimeters and areas (FINISHED)
- move shapes (FINISHED)
- save shapes file and re-write it for next time the project runs (FINISHED)

- add a "contact us section", with team name and logo (FINISHED)

- create uml diagrams of the project(FINISHED)
- run valgrind(FINISHED)
- run doxygen(FINISHED)

- make everything look pretty(FINISHED)
and thats literally it




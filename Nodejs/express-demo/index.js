const Joi = require('joi');
const express = require('express');
const app = express();

app.use(express.json());

const courses = [
        {id: 1, name: 'course1'},
        {id: 2, name: 'course2'},
        {id: 3, name: 'course3'},
];
app.get('/',(req, res) => {
    res.send('Hello World');
});

app.get('/api/courses', (req, res) => {
    res.send([1,2,3]);
});

app.post('/api/courses', (req, res) => {
    //if(!req.body.name || req.body.name.length < 3) {
    //    res.status(400).send('Name is required and should be minimum 3 characters');
    //    return ;
    //}
    const { error } = validateCourse(req.body);
    //const result = validateCourse(req.body);
    if(error)
        return res.status(400).send(result.error.details[0].message);
    const course = {
        id: courses.length + 1,
        name: req.body.name
    };
    courses.push(course);
    res.send(course);
});

app.put('/api/courses/:id', (req, res) => {
    //look up the course
    //if not existing, return 404
    var course = courses.find(c => c.id === parseInt(req.params.id));
    if(!course)
        return res.status(404).send('The course with the given ID was not found');
    //validation
    //if invalid, return 400
    const { error } = validateCourse(req.body);
    //const result = validateCourse(req.body);
    if(error)
        return res.status(400).send(result.error.details[0].message);
    
    //update course
    course.name = req.body.name;
    //return updated course
    res.send(course);
});

function validateCourse(course) {
    const schema = {
        name: Joi.string().min(3).required()
    };
    return Joi.validate(course, schema);
}

app.delete('/api/courses/:id', (req, res) => {
    //look up the course
    //not existing, return 404
    var course = courses.find(c => c.id === parseInt(req.params.id));
    if(!course) 
        return res.status(404).send('The course with the given ID was not found');
    //delete
    const index = courses.indexOf(course);
    courses.splice(index, 1);
    
    res.send(course);
});

app.get('/api/courses/:id', (req, res) => {
    //res.send(req.param.id);
    //res.send(req.query);
    var course = courses.find(c => c.id === parseInt(req.params.id));
    if(!course) 
        return res.status(404).send('The course with the given ID was not found');
    res.send(course);
});

app.listen(3000, () => console.log('Listening on port 3000...'));
'use strict';
const express = require('express');
const app = express();
app.use(express.json());

let users = [
    { id: 1, name: "Jane", email: "jane@etsy.com", active: true, purchases: 5 },
    { id: 2, name: "John", email: "john@etsy.com", active: false, purchases: 2 },
    { id: 3, name: "Sara", email: "sara@etsy.com", active: true, purchases: 8 },
    { id: 4, name: "Mike", email: "mike@etsy.com", active: true, purchases: 1 }
];

// Bug 1: Should return only active users
app.get('/users/active', (req, res) => {
    const active =  users.filter(user => user.active === true);
    res.json(active);
});

app.get('/allusers', (req, res) => {
    res.json(users);
});

// Bug 2: Should add a new user
app.post('/users', (req, res) => {
    const newUser = {
        id: users.length + 1, // because we start at index 0 we need avoid the dupe 
        name: req.body.name,
        email: req.body.email,
        active: true,
        purchases: 0
    };
    users.push(newUser);
    res.json(newUser);
});

// Bug 3: Should return user with most purchases
app.get('/users/top', (req, res) => {
    const top = users.reduce((max, user) => user.purchases > max.purchases ? user : max);
    res.json(top);
});

// TODO 1: Add a route to deactivate a user
// PUT /users/:id/deactivate
// Should set active to false
// Return the updated user
app.put('/users/:id/deactive', (req, res) => {
    const id = parseInt(req.params.id);
    const user = users.find(user => user.id === id);
    user.active = false;
    res.json(user);
})

// TODO 2: Add a route to get purchase stats
// GET /users/stats
// Should return { totalUsers: 4, activeUsers: 3, totalPurchases: 16, avgPurchases: 4 } 
// creating values that do not exit in the arr
app.get('/users/stats', (req, res) => {
    const stats = users.reduce((count , user) => {
        count.totalUsers  += 1; // track user amount per loop
        count.totalPurchases += user.purchases;  //create new values to store new info
        if(user.active) count.activeUsers += 1;
        return count;
    }, {totalUsers: 0, activeUsers: 0, totalPurchases: 0, avgPurchases: 0 }); //base case, defining

    stats.avgPurchases = stats.totalPurchases / stats.totalUsers;
    res.json(stats);
});

app.listen(3000, () => console.log('Server running on port 3000')); 
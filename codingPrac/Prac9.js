'use strict';
const express = require('express');
const app = express();
app.use(express.json());

let listings = [
    { id: 1, title: "Vintage Mug", price: 15, favorite: false },
    { id: 2, title: "Wool Scarf", price: 25, favorite: false },
    { id: 3, title: "Leather Bag", price: 50, favorite: false }
];

// Bug 1: Should return all listings but something is wrong
app.get('/listings', (req, res) => {
    res.json(listings);
    //if we know if json , just use it instead of send
});

// Bug 2: Should return a single listing by id
app.get('/listings/:id', (req, res) => {
    const listing = listings.find(item => item.id === parseInt(req.params.id)); //parseInt converts to check
    res.json(listing);
});

// Bug 3: Should delete a listing by id
app.delete('/listings/:id', (req, res) => {
    listings = listings.filter(item => item.id !== parseInt(req.params.id));
    res.json({ success: true });
   
});

// TODO: Add a favorite feature
// POST /listings/:id/favorite
// Should toggle the favorite property on the listing
// Return the updated listing
app.post('/listings/:id/favorite', (req, res) => {
   const idFav = parseInt(req.params.id);
   const listing = listings.find(item => item.id === idFav); 
   listing.favorite = !listing.favorite; //if true then false, else true
   res.json(listing);
});

app.listen(3000, () => console.log('Server running on port 3000'));
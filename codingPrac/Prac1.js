'use strict';

// Bug 1: This should fetch shop data but something is wrong
var getShopData = async function(shopID) {
    const res = await fetch(`https://api.etsy.com/shops/${shopID}`);
    const data = await res.json();
    return data;
};

// Bug 2: This should return all listings over $20
var getExpensiveListings = function(listings) {
    return listings.filter(item => item.price > 20);
};

// Bug 3: This should add up total views across all listings
var getTotalViews = function(listings) {
    return listings.reduce((total, item) => total + item.views, 0);
        // total is the item being incremented, item is the looping element.  total + item.views is the same as total += .views
        //0 is what is starts with , basically i = 0;
};

// TODO: Implement this — takes an array of listings and returns
// only the ones that are active AND have more than 10 views
var getPopularActiveListings = function(listings) {
    return listings.filter(views => views.views > 10 && views.active === true);
    //views is the item being lopp through, next is just the arguments
};

const listings = [
    { name: "hat", price: 25, views: 15, active: true },
    { name: "shirt", price: 15, views: 5, active: true },
    { name: "bag", price: 30, views: 20, active: false },
    { name: "shoes", price: 50, views: 12, active: true }
];

console.log(getExpensiveListings(listings));
console.log(getTotalViews(listings));
console.log(getPopularActiveListings(listings));
'use strict';

var fetchListings = async function() {
    return [
        { name: "hat", price: 25, views: 15, active: true, tags: ["accessories", "winter"] },
        { name: "shirt", price: 15, views: 5, active: false, tags: ["clothing"] },
        { name: "bag", price: 30, views: 20, active: true, tags: ["accessories"] },
        { name: "shoes", price: 50, views: 12, active: true, tags: ["clothing", "winter"] },
        { name: "scarf", price: 20, views: 8, active: true, tags: ["accessories", "winter"] }
    ];
};

// Bug 1: Should return only active listings
var getActiveListings = async function() {
    const listings =  await fetchListings();
    return listings.filter(item => item.active === true);
};

// Bug 2: Should return all unique tags across all listings
var getAllTags = function(listings) {
    const tags = listings.map(item => item.tags);
    return [...new Set(tags.flat())];
};

// Bug 3: Should return average price of active listings only
var getAveragePrice = function(listings) {
    const active = listings.filter(item => item.active === true);
    const total = active.reduce((sum, item) => sum + item.price, 0);
    return total / active.length;
};

// TODO: takes listings and a tag (string) 
// returns all active listings that include that tag, sorted by price low to high
var getListingsByTag = function(listings, tag) {                   // we not using === because tags is an array, so include works here to check if it exits
    const items = listings.filter(item => item.active === true && item.tags.includes(tag));
    //sorts by accending order
    items.sort((a, b) => a.price - b.price);
    return items;
};

var main = async function() {
    const listings = await fetchListings();
    const active = await getActiveListings();
    console.log("Active listings:", active.length); // should be 4
    console.log("All tags:", getAllTags(listings)); // should be ["accessories", "winter", "clothing"]
    console.log("Average price:", getAveragePrice(listings)); // should be 28
    console.log("Winter accessories:", getListingsByTag(listings, "winter")); // hat, shoes, scarf sorted by price
};

main();
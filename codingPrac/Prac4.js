'use strict';

// Simulated API call - pretend this is hitting a real endpoint
// Returns 3 listings at a time with pagination info
var fetchPage = async function(offset) {
    const allListings = [
        { name: "hat", price: 25, views: 15 },
        { name: "shirt", price: 15, views: 5 },
        { name: "bag", price: 30, views: 20 },
        { name: "shoes", price: 50, views: 12 },
        { name: "scarf", price: 20, views: 8 },
        { name: "gloves", price: 18, views: 3 },
        { name: "jacket", price: 80, views: 25 }
    ];

    const limit = 3;
    const results = allListings.slice(offset, offset + limit);
    const nextOffset = offset + limit < allListings.length ? offset + limit : null;

    return {
        results: results,
        pagination: {
            next_offset: nextOffset
        }
    };
};

// Bug 1: This should fetch ALL listings across all pages but something is wrong
var getAllListings = async function(offset, results) {
    const data = await fetchPage(offset);
    //not needed cause data was already promised
    results = results.concat(data.results); //concat is arr method
    if (data.pagination.next_offset != null) {
        // any call on itself(recursion) must need a promise aswell
        //that way it does not skip to the return statement with unfinished data
        results = await getAllListings(offset + 3, results);
    }
    return results;
};

// Bug 2: This should return the most expensive item but something is wrong
var getMostExpensive = function(listings) {
    return listings.reduce((max, item) => item.price > max.price ? item : max);
};

// TODO: Implement this — call getAllListings starting at offset 0
// then log how many total listings were fetched
var main = async function() {
    const results = await getAllListings(0, []); // we used a empty arr because later with fill it with the data. start at 0 to check lentgh from start point
    console.log(results.length);
};

main();
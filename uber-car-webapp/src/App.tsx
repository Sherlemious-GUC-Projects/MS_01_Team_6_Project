import React, { useState, useEffect } from "react";
import { MapPin, Car, Navigation, Play } from "lucide-react";
import Map from "./components/Map";
import axios from "axios";

interface ILocation {
  lat: number;
  lng: number;
  name?: string;
  timestamp?: Date;
}

const App: React.FC = () => {
  const picoIpAddress = "http://192.168.106.90:80";
  const [carLocation, setCarLocation] = useState<ILocation | null>(null);
  const [destinationLocation, setDestinationLocation] =
    useState<ILocation | null>(null);
  const [isMoving, setIsMoving] = useState(false);
  const [compassHeading, setCompassHeading] = useState<number | null>(null);

  const sendCoordinatesToPico = async (location: ILocation) => {
    try {
      const payload = {
        car: {
          latitude: carLocation?.lat,
          longitude: carLocation?.lng,
        },
        destination: {
          latitude: location.lat,
          longitude: location.lng,
        },
        heading: compassHeading,
      };

      const response = await axios.post(picoIpAddress, JSON.stringify(payload), {
        headers: {
          "Content-Type": "application/json",
          'Accept': "application/json",
        },
      });

      if (response.status === 200) {
        console.log(response.data);
      }
    } catch (error) {
      console.error("Error sending coordinates to Pico W:", error);
      alert("Could not send location to the car");
    }
  };

  const handleDestinationChange = (carLocation: ILocation, destination: ILocation) => {
    setCarLocation(carLocation);
    setDestinationLocation(destination);
    setIsMoving(false);
  };

  const handleStartMoving = () => {
    if (!destinationLocation) {
      alert("Please select a destination first!");
      return;
    }

    setIsMoving(true);
    sendCoordinatesToPico(destinationLocation);
    console.log("Starting movement to:", destinationLocation);
  };

  const handleOrientation = (event: DeviceOrientationEvent) => {
    if (event.alpha !== null) {
      setCompassHeading(event.alpha);
    }
  };

  const requestCompassAccess = async () => {
    if (
      typeof (DeviceOrientationEvent as any).requestPermission === "function"
    ) {
      try {
        const permission = await (
          DeviceOrientationEvent as any
        ).requestPermission();
        if (permission === "granted") {
          window.addEventListener("deviceorientation", handleOrientation);
        } else {
          alert("Permission to access compass was denied.");
        }
      } catch (error) {
        console.error("Error accessing compass:", error);
      }
    } else {
      window.addEventListener("deviceorientation", handleOrientation);
    }
  };

  useEffect(() => {
    return () => {
      window.removeEventListener("deviceorientation", handleOrientation);
    };
  }, []);

  return (
    <div className="min-h-screen bg-gradient-to-br from-blue-50 to-blue-100 flex flex-col">
      <header className="bg-white shadow-md p-4 flex items-center justify-between">
        <div className="flex items-center space-x-3">
          <Car className="text-blue-600" size={32} />
          <h1 className="text-2xl font-bold text-gray-800">
            Smart Car Tracker
          </h1>
        </div>
        {carLocation && (
          <div className="flex items-center space-x-1 bg-green-100 px-3 py-1 rounded-full">
            <MapPin size={16} className="text-green-600" />
            <span className="text-sm text-green-800">Connected</span>
          </div>
        )}
      </header>

      <main className="flex-grow flex flex-col lg:flex-row p-4 space-y-4 lg:space-y-0 lg:space-x-4">
        <div className="lg:w-2/3 h-[500px] bg-white rounded-xl shadow-lg overflow-hidden">
          <Map
            className="w-full h-full"
            defaultMark={carLocation || undefined}
            onChange={handleDestinationChange}
            defaultCenter={carLocation || undefined}
          />
        </div>

        <div className="lg:w-1/3 space-y-4">
          {carLocation && (
            <div className="bg-white rounded-xl shadow-md p-4 space-y-2">
              <h2 className="text-xl font-semibold text-gray-800 flex items-center">
                <Navigation className="mr-2 text-blue-600" size={24} />
                Current Location Details
              </h2>
              <p>
                <strong>Latitude:</strong> {carLocation.lat.toFixed(4)}
              </p>
              <p>
                <strong>Longitude:</strong> {carLocation.lng.toFixed(4)}
              </p>
            </div>
          )}

          {destinationLocation && (
            <div className="bg-white rounded-xl shadow-md p-4 space-y-2">
              <h2 className="text-xl font-semibold text-gray-800 flex items-center">
                <Navigation className="mr-2 text-blue-600" size={24} />
                Destination Details
              </h2>
              <p>
                <strong>Latitude:</strong> {destinationLocation.lat.toFixed(4)}
              </p>
              <p>
                <strong>Longitude:</strong> {destinationLocation.lng.toFixed(4)}
              </p>
              <p>
                <strong>Location:</strong> {destinationLocation.name}
              </p>
            </div>
          )}

          <div className="bg-white rounded-xl shadow-md p-4 space-y-2">
            <h2 className="text-xl font-semibold text-gray-800 flex items-center">
              <Navigation className="mr-2 text-blue-600" size={24} />
              Compass Heading
            </h2>
            {compassHeading !== null ? (
              <p>
                <strong>Heading:</strong> {compassHeading.toFixed(2)}°
              </p>
            ) : (
              <button
                onClick={requestCompassAccess}
                className="bg-blue-600 text-white py-2 px-4 rounded"
              >
                Enable Compass
              </button>
            )}
          </div>

          <button
            onClick={handleStartMoving}
            disabled={!destinationLocation || isMoving}
            className={`w-full py-3 rounded-xl text-white font-bold flex items-center justify-center space-x-2 transition-all duration-300 ${
              destinationLocation && !isMoving
                ? "bg-blue-600 hover:bg-blue-700 active:scale-95"
                : "bg-gray-400 cursor-not-allowed"
            }`}
          >
            <Play size={24} />
            <span>{isMoving ? "Moving..." : "Start Moving"}</span>
          </button>
        </div>
      </main>

      <footer className="bg-white shadow-md p-4 text-center text-gray-600">
        © 2024 Smart Car Tracking System
      </footer>
    </div>
  );
};

export default App;

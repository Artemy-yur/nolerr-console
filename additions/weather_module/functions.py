import requests, json
from pathlib import Path


def get_data_from_json(filename):
    try:
        file_path = Path(__file__).parent / filename
        with open(file_path, 'r', encoding='utf-8') as f:
            data = json.load(f)
        return data
    except Exception as e:
        print(e)
        return None

def get_weather_json(
        city, apiKey, units, forecast,
        lang="en"
    ):
    url = "https://api.openweathermap.org/data/2.5/forecast" if forecast else "https://api.openweathermap.org/data/2.5/weather"
    try:
        request = requests.get(
            url=url,
            params={
                "q": city,
                "appid": apiKey,
                "units": units,
                "lang": lang
            }
        )
    except Exception as e:
        print(e)
        return None
    
    return json.loads(request.text)



def parse_current_weather(json):
    if not json:
        return None
    
    try:
        main = json["main"]
        weather = json["weather"][0]
        wind = json["wind"]
        
        current = {
            "temperature": main["temp"],
            "feels_like": main["feels_like"],
            "temp_min": main["temp_min"],
            "temp_max": main["temp_max"],
            "pressure": main["pressure"],
            "humidity": main["humidity"],
            "description": weather["description"],
            "wind_speed": wind["speed"]
        }
        
        print(f"Temperature: {current['temperature']}")
        print(f"Feels like: {current['feels_like']}")
        print(f"Min/Max: {current['temp_min']} / {current['temp_max']}")
        print(f"Description: {current['description']}")
        print(f"Wind: {current['wind_speed']}")
        print(f"Humidity: {current['humidity']}%")

    except Exception as e:
        print(e)
        return



def parse_forecast_weather(json):
    if not json:
        return None
    
    daily_data = {}
    
    try:
        for item in json["list"]:
            date = item["dt_txt"].split()[0]
            
            if date not in daily_data:
                daily_data[date] = {
                    "temps": [],
                    "feels_like": [],
                    "weather": []
                }
            
            daily_data[date]["temps"].append(item["main"]["temp"])
            daily_data[date]["feels_like"].append(item["main"]["feels_like"])
            daily_data[date]["weather"].append(item["weather"][0]["description"])

        for date, data in daily_data.items():
            temps = data["temps"]
            feelsLike = data["feels_like"]

            print("Date:", date)
            print(f"Average temp: {(sum(temps) / len(temps)):.1f}")
            print("Min temp:", min(temps))
            print("Max temp:", max(temps))
            print(f"Feels like: {(sum(feelsLike) / len(feelsLike)):.1f}")
            print(f"Description: {', '.join(set(data['weather']))}")
            print()
            
    except Exception as e:
        print(e)
        return